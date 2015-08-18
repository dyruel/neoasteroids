mainmenu={}


local NewGameItem = {name = "New Game", action = ingame.enter}
local QuitItem = {name = "Quit", action = love.event.quit}
local menuItems = {NewGameItem, QuitItem}
local menuCursor = 1

function mainmenu.enter()
	state = STATE_MAINMENU


end

function mainmenu.keypressed(key, isrepeat)
	if isrepeat then
		return
	end

	if key == "up" then
		menuCursor = menuCursor - 1
	end

	if key == "down" then
		menuCursor = menuCursor + 1
	end

	if menuCursor < 1 then
		menuCursor = 1
	elseif menuCursor > 2 then
		menuCursor = 2
	end

	if key == "return"  then
		menuItems[menuCursor].action()
	end

end

function mainmenu.keyreleased(key)

end

function mainmenu.update(dt)

end

function mainmenu.draw()
	love.graphics.push()
	love.graphics.origin()

	for idx, menuItem in ipairs(menuItems) do
		if idx == menuCursor then
			love.graphics.setColor(0, 255, 0);
		else
			love.graphics.setColor(255, 255, 255);
		end
		love.graphics.print(menuItem.name, 0, 10*idx)
	end

	love.graphics.pop()
end