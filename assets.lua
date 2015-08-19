
snd = {}

local SOUND_FILES = { "laser" }

function loadAssets()

	-- Load sounds
	for i,v in ipairs(SOUND_FILES) do
		snd[v] = love.audio.newSource("data/"..v..".wav","static")
--		snd[v]:addTags("sfx")
	end
end

function playMusic(name, loop)
	-- Stop previously playing music if any
	if music then
		music:stop()
	end
	-- Play new file
	music_name = name
	music = love.audio.newSource("data/"..name..".ogg", "stream")
--	music:addTags("music")
	if loop ~= nil then
		music:setLooping(loop)
	else
		music:setLooping(true)
	end
--	love.audio.tags.music.setVolume(config.music_volume)
	love.audio.play(music)
end

function stopMusic()
	if music then
		music:stop()
	end
end
