
-- general
Description="h3lp"
Categories={"source"}
IgnoreCase=false
EnableIndentation=true
PreProcessor={Prefix=[[#]], Continuation="\\"}
Strings={Delimiter=[["|']], RawPrefix="R", Interpolation=[[ %\w ]]}
Digits=[[ (?:0x|0X|0b)[0-9a-fA-F']+|\d*[\.]?\d+(?:[eE][\-\+]\d+)?[lLuU]* ]]
Operators=[[\(|\)|\[|\]|\{|\}|\,|\;|\.|\:|\&|<|>|\!|=|\/|\*|\%|\+|\-|\~|\||\^|\?]]

-- key words
Keywords={
	{Id=1, List={
		"DESCRIPTION", "COMMANDS", "SHORTCUTS", "DEPENDS", "ON", "REQUIRED", "BY",
		"BINARIES", "FILES", "COMMON", "USAGE", "WEBLINKS", "OPERATORS", "BUILTINS",
		"GUI", "SPECS", "TEAM", "COMMUNICATION", "GAME", "HUD", "VIDEO", "ADVANCED",
		"AUDIO", "MUSIC", "SPECTATOR", "SCOREBOARD", "ITEMS", "RADAR", "CROSSHAIR",
		"KEYBINDINGS", "CHAT", "WHEELS"}},
	{Id=2, Regex=[=[\_]=]}, -- underscore chars '_'
	{Id=3, Regex=[[\<.*?\>]]}, -- in angle brackets '<...>'
	{Id=4, Regex=[[ [▪▸•] ]]}, -- unicode chars '▪', '▸' and '•'
	{Id=5, Regex=[=[ \[\[[\w\:\,\s]+?\]\] ]=]}, -- in square brackets '[...]'
	{Id=6, Regex=[[\$\{[^\}]+\$\{.+?\}.+?\}|\$\{.+?\}|\$\(.+?\)]]} -- nested vars '$(...)' '${...}'
}

-- comments
Comments={
	{Block=true, Nested=false, Delimiter={[[\/\*]], [[\*\/]]}}, -- c multiline
	{Block=false, Delimiter={[[//]]}}, -- c single line
	{Block=false, Delimiter={[[#]]}}, -- bash single line
}

-- ignore apostrophes
function OnStateChange(oldState, newState, token)
	if token=="'" and oldState==HL_NUMBER and newState==HL_STRING then
		return HL_NUMBER
	end
	return newState
end
