--require("debug")
require("ingame")
require("mainmenu")


local MAX_FRAMETIME = 1/20
local MIN_FRAMETIME = 1/60

STATE_SPLASH, STATE_INGAME, STATE_MAINMENU = 0, 1, 2

gamestates = {[STATE_SPLASH]=splash, [STATE_INGAME]=ingame, [STATE_MAINMENU]=mainmenu}

function love.keypressed(key, isrepeat)
	gamestates[state].keypressed(key, isrepeat)
end

function love.keyreleased(key)
	gamestates[state].keyreleased(key)
end

-- Load some default values for our rectangle.
function love.load()
	love.graphics.setBackgroundColor(0,0,0)
	love.graphics.setDefaultFilter("nearest","nearest")

	font = love.graphics.newImageFont("data/font.png",
    		" abcdefghijklmnopqrstuvwxyz" ..
    		"ABCDEFGHIJKLMNOPQRSTUVWXYZ0" ..
    		"123456789.,!?-+/():;%&`'*#=[]\"")

	love.graphics.setFont(font)
	love.graphics.setLineWidth(0.005)
	love.graphics.setLineStyle("smooth")
	love.window.setFullscreen( false )

	mainmenu.enter();
end
 
-- Increase the size of the rectangle every frame.
function love.update(dt)
	gamestates[state].update(dt)
end
 
-- Draw a coloured rectangle.
function love.draw()
--	love.graphics.setColor(0, 100, 100);
--love.graphics.print("hello", 0, 0)
	love.graphics.push()
	love.graphics.origin()
	love.graphics.scale(love.graphics.getWidth()/2, love.graphics.getHeight()/2)
	love.graphics.translate(1, 1)
	love.graphics.scale(1, -1)
	gamestates[state].draw()
	love.graphics.pop()
end


function love.run()
    math.randomseed(os.time())
    math.random() math.random()

    if love.load then love.load(arg) end
    local dt = 0
	local acc = 0

    -- Main loop time.
    while true do
		local frame_start = love.timer.getTime()
        -- Process events.
        if love.event then
            love.event.pump()
            for e,a,b,c,d in love.event.poll() do
                if e == "quit" then
                    if not love.quit or not love.quit() then
                        if love.audio then
                            love.audio.stop()
                        end
                        return
                    end
                end
                love.handlers[e](a,b,c,d)
            end
        end

		love.timer.step()
		dt = love.timer.getDelta()
		dt = math.min(dt, MAX_FRAMETIME)
		acc = acc + dt

		while acc >= MIN_FRAMETIME do
			love.update(MIN_FRAMETIME)
			acc = acc - MIN_FRAMETIME
		end

		-- Update screen
		love.graphics.clear()
		love.draw()

		love.graphics.present()
		love.timer.sleep(0.001)
    end
end