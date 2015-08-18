ingame={}


local asteroidSize = {0.1, 0.06, 0.03}
local worldObjects = {}

local thrustFactor = 1
local frictionFactor = 0.99
local angleDir = 0
local thrust = 0
local hitCounter = 0

function ingame.enter()
	state = STATE_INGAME

	worldObjects.ship = {}

  	worldObjects.ship.angle = 0
  	worldObjects.ship.posx = 0
 	worldObjects.ship.posy = 0
   	worldObjects.ship.velx = 0
 	worldObjects.ship.vely = 0
    worldObjects.ship.accx = 0
 	worldObjects.ship.accy = 0
 	worldObjects.ship.fireCd = 0 -- fire cooldown
 	worldObjects.ship.shape = {-0.05, 0.05,  -0.05, -0.05,  0.05, 0}
 	worldObjects.ship.vertices = worldObjects.ship.shape

 	worldObjects.asteroids = {}
	for i = 1,4 do
		worldObjects.asteroids[i] = generateAsteroid(nil, 1)
	end

	worldObjects.bullets = {}
	for i = 1,4 do
		worldObjects.bullets[i] = {}
		worldObjects.bullets[i].posx = 0
		worldObjects.bullets[i].posy = 0
		worldObjects.bullets[i].velx = 0
		worldObjects.bullets[i].vely = 0
		worldObjects.bullets[i].alive = false
		worldObjects.bullets[i].timer = 0
		worldObjects.bullets[i].radius = 0.005
		worldObjects.bullets[i].angle = 0
		worldObjects.bullets[i].speed = 1
	end	

end

function ingame.keypressed(key, isrepeat)
	if isrepeat then
		return
	end

	if key == "up" then
		thrust = 1
	end

	if key == "right" then
		angleDir = -1
	elseif key == "left" then
		angleDir = 1		
	end

	if key == " " then
		generateBullet()
	end	

end

function ingame.keyreleased(key)
	if key == "up" then
		thrust = 0
	end

	if key == "right" and angleDir == -1 then 
		angleDir = 0
	end

	if key == "left" and angleDir == 1 then 
		angleDir = 0
	end	
end


function ingame.update(dt)

	-- Move ship
	worldObjects.ship.angle = worldObjects.ship.angle + angleDir * math.pi * dt
	worldObjects.ship.angle = worldObjects.ship.angle % (2*math.pi)

	worldObjects.ship.accx = math.cos(worldObjects.ship.angle) * thrustFactor * thrust 
	worldObjects.ship.accy = math.sin(worldObjects.ship.angle) * thrustFactor * thrust

	worldObjects.ship.velx = worldObjects.ship.velx + worldObjects.ship.accx * dt
	worldObjects.ship.vely = worldObjects.ship.vely + worldObjects.ship.accy * dt

	worldObjects.ship.posx = worldObjects.ship.posx + worldObjects.ship.velx * dt
	worldObjects.ship.posy = worldObjects.ship.posy + worldObjects.ship.vely * dt

	worldObjects.ship.velx = worldObjects.ship.velx * frictionFactor
	worldObjects.ship.vely = worldObjects.ship.vely * frictionFactor

	clampObjectPosition(worldObjects.ship)

	worldObjects.ship.vertices = rotateTranslate(worldObjects.ship.angle, worldObjects.ship.posx, worldObjects.ship.posy, worldObjects.ship.shape)

	-- Move asteroids
	for key, asteroid in pairs(worldObjects.asteroids) do
		if asteroid.alive then
			asteroid.velx = math.cos(asteroid.angle) * asteroid.speed
			asteroid.vely = math.sin(asteroid.angle) * asteroid.speed

			asteroid.posx = asteroid.posx + asteroid.velx * dt
			asteroid.posy = asteroid.posy + asteroid.vely * dt

			asteroid.vertices = rotateTranslate(asteroid.angle, asteroid.posx, asteroid.posy, asteroid.shape)

			-- Check for collisions
			if shipAsteroidCollision(worldObjects.ship, asteroid) then
				resetShip()
			end

			clampObjectPosition(asteroid)
		end
	end

	-- Move bullets
	for key, bullet in pairs(worldObjects.bullets) do
		if bullet.alive then
			bullet.velx = math.cos(bullet.angle) * bullet.speed
			bullet.vely = math.sin(bullet.angle) * bullet.speed

			bullet.posx = bullet.posx + bullet.velx * dt
			bullet.posy = bullet.posy + bullet.vely * dt

			if bullet.timer > 0 then
				bullet.timer = bullet.timer - 0.01
			else
				bullet.alive  = false
			end


			for key, asteroid in pairs(worldObjects.asteroids) do
				if asteroid.alive then	
					if bulletAsteroidCollision(bullet, asteroid) then
						bullet.alive  = false
						asteroid.alive = false
						if asteroid.size < 3 then
							table.insert(worldObjects.asteroids, generateAsteroid(nil, asteroid.size+1, asteroid.posx, asteroid.posy))
							table.insert(worldObjects.asteroids, generateAsteroid(nil, asteroid.size+1, asteroid.posx, asteroid.posy))
						end
					end
				end
			end
		end
	end

	-- logic
	if worldObjects.ship.fireCd > 0 then
		worldObjects.ship.fireCd = worldObjects.ship.fireCd - 0.1
	end

end

function ingame.draw()
	love.graphics.setColor(0, 100, 0);
	love.graphics.push()
	love.graphics.origin()
	love.graphics.print("Hits : "..hitCounter, 0, 0)
	love.graphics.print("Current FPS: "..tostring(love.timer.getFPS( )), 0, 10)
	love.graphics.pop()

	-- Draw ship
	--love.graphics.setColor(100, 0, 0)
	glowEffect(255, 0, 0, "polygon", worldObjects.ship.vertices)
	--love.graphics.polygon("line", worldObjects.ship.vertices)

	-- Draw asteroids
	--love.graphics.setColor(0, 100, 0)
	for key, asteroid in pairs(worldObjects.asteroids) do
		if asteroid.alive then
			glowEffect(0, 255, 0, "polygon", asteroid.vertices)
		end
		--love.graphics.polygon("line", asteroid.vertices)
	end

	-- Draw bullets
	--love.graphics.setColor(0, 100, 0)
	for key, bullet in pairs(worldObjects.bullets) do
		if bullet.alive then
			glowEffect(0, 0, 255, "circle", bullet.posx, bullet.posy, bullet.radius)
			--love.graphics.circle("line", bullet.posx, bullet.posy, bullet.radius)
		end
	end	
end



function resetShip()
	hitCounter = hitCounter + 1
  	worldObjects.ship.angle = 0
  	worldObjects.ship.posx = 0
 	worldObjects.ship.posy = 0
   	worldObjects.ship.velx = 0
 	worldObjects.ship.vely = 0
    worldObjects.ship.accx = 0
 	worldObjects.ship.accy = 0
 	worldObjects.ship.fireCd = 0
 	worldObjects.ship.vertices = worldObjects.ship.shape
end

function bulletAsteroidCollision(bullet, asteroid)
	return pointInsidePolygon({bullet.posx, bullet.posy}, asteroid.vertices)
end

function shipAsteroidCollision(ship, asteroid)
	local i = 1
	local v = {}

	local numVertices = #ship.vertices * 0.5

	while i <= numVertices do
		v[1] = ship.vertices[2*i-1]
		v[2] = ship.vertices[2*i]
		if pointInsidePolygon(v, asteroid.vertices) then
			return true
		end
		i = i + 1
	end

	i = 1
	numVertices = #asteroid.vertices * 0.5

	while i <= numVertices do
		v[1] = asteroid.vertices[2*i-1]
		v[2] = asteroid.vertices[2*i]
		if pointInsidePolygon(v, ship.vertices) then
			return true
		end
		i = i + 1
	end	

	return false
end

function pointInsidePolygon(v,polygon)

	local numVertices = #polygon * 0.5
	local i = 1
	local j = numVertices
	local p1 = {}
	local p2 = {}
	local parity = false

	while i <= numVertices do
		p1[1] = polygon[2*i-1]
		p1[2] = polygon[2*i]
		p2[1] = polygon[2*j-1]
		p2[2] = polygon[2*j]

		if (v[2] > p1[2] and v[2] <= p2[2]) or (v[2] <= p1[2] and v[2] > p2[2]) then
			if p1[1] <= v[1] or p2[1] <= v[1] then
				if p1[1] + ((v[2] - p1[2])*(p2[1] - p1[1]) / (p2[2] - p1[2])) < v[1] then
					parity = not parity
				end
			end
		end

		j = i
		i = i + 1
	end

	return parity
end


function generateAsteroid(n, size, posx, posy)
	local asteroid = {}

	if not size then size = 0.1 end
	if not n then n = 20 end
	if not posx or not posy then
		asteroid.posx = math.random(-100,100)*0.01
		asteroid.posy = math.random(-100,100)*0.01
	else
		asteroid.posx = posx
		asteroid.posy = posy	
	end

	local i = 1
	local step = 2*math.pi / n
	local polygon = {}
	local perturbFactor = 1

	while i <= n do
		perturbFactor 	= math.random(70,130)*0.01
		polygon[2*i-1]  = math.cos(step*(i-1)) * perturbFactor * asteroidSize[size]
		polygon[2*i] 	= math.sin(step*(i-1)) * perturbFactor * asteroidSize[size]
		i = i + 1
	end

	asteroid.velx = 0
	asteroid.vely = 0
	asteroid.alive = true
	asteroid.size = size
	asteroid.angle = math.random(0,100) * 0.01 * 2 * math.pi
	asteroid.speed = 0.3 + math.random(0,100) * 0.01 * 0.5
	asteroid.shape = polygon
	asteroid.vertices = polygon

	return asteroid
end

function generateBullet()
	local k = -1

	if worldObjects.ship.fireCd > 0 then
		return
	end

	for i = 1,4 do
		if not worldObjects.bullets[i].alive then
			k = i
			break
		end
	end

	if k > 0 then
		worldObjects.bullets[k].alive = true
		worldObjects.bullets[k].timer = 2 -- last 2 seconds
		worldObjects.bullets[k].posx = worldObjects.ship.vertices[5]
		worldObjects.bullets[k].posy = worldObjects.ship.vertices[6]
		worldObjects.bullets[k].angle = worldObjects.ship.angle
		worldObjects.bullets[k].velx = 0
		worldObjects.bullets[k].vely = 0
	end
end

function clampObjectPosition(obj)
	if obj.posx > 1.2 then
		obj.posx = -1.2
	end

	if obj.posx < -1.2 then
		obj.posx = 1.2
	end

	if obj.posy > 1.2 then
		obj.posy = -1.2
	end

	if obj.posy < -1.2 then
		obj.posy = 1.2
	end
end

function rotateTranslate(angle, tx, ty, vertices)
	local numVertices = #vertices * 0.5
	local i = 1
	local r = {}

	while i <= numVertices do
		r[2*i-1] 	= vertices[2*i-1]
		r[2*i] 		= vertices[2*i]

		-- Rotate
		if angle then
			r[2*i-1], r[2*i] = rotate(angle, r[2*i-1], r[2*i])
		end

		-- Translate
		if tx and ty then
			r[2*i-1], r[2*i] = r[2*i-1] + tx, r[2*i] + ty
		end

		i = i + 1
	end

	return r
end

function rotate(angle, x, y)
	local c, s = math.cos(angle), math.sin(angle)
	return c*x - s*y, s*x + c*y
end

function glowEffect(r, g, b, type, ...)
  love.graphics.setColor(r, g, b, 15)
  
  --print("a")
  for i = 10, 2, -1 do
  	--print(i)
    if i == 2 then
    	i = 1
    	love.graphics.setColor(r, g, b, 255)    
    end
    
    love.graphics.setLineWidth(i * 0.001)
    
    if type == "line" then
      love.graphics[type](...)
    else
      love.graphics[type]("line", ...)
    end
  end
  --print("b")
end
