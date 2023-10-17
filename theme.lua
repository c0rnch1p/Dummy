
-- general
Description="h3lp"
Categories={"dark", "base16", "lsp"}

-- palette
base00="#101010" -- black
base01="#ff40ff" -- pink
base02="#e10000" -- red
base03="#c6c6ac" -- grey yellow
base04="#ffffff" -- grey
base05="#0cd019" -- ill green
base06="#008436" -- sexy green
base07="#8cfe6b" -- green
base08="#5d00c3" -- dark purple
base09="#58c485" -- turqoise
base0A="#ffffff" -- white
base0B="#caaaff" -- purple
base0C="#b42fea" -- hard purple
base0D="#baff29" -- hard green
base0E="#006cd2" -- hard blue
base0F="#194f19" -- dark green

--  text types
BlockComment={Colour=base03, Italic=true, Bold=true} -- multi line comments
Canvas={Colour=base00, Italic=false, Bold=true} -- default background
Default={Colour=base06, Italic=false, Bold=true} -- default foreground text
Escape={Colour=base0C, Italic=false, Bold=true} -- escape sequenced strings
Interpolation={Colour=base09, Italic=false, Bold=true} -- interpolated strings (placeholders)
LineComment={Colour=base03, Italic=true, Bold=false} -- single line comment blocks
LineNum={Colour=base0E, Italic=false, Bold=flase} -- line numbers
Number={Colour=base09, Italic=false, Bold=true} -- numeric values
Operator={Colour=base06, Italic=false, Bold=true} -- logic and arithmetic operators
PreProcessor={Colour=base0F, Italic=false, Bold=true} -- deprecated
String={Colour=base05, Italic=false, Bold=true} -- regular expressions
StringPreProc={Colour=base0C, Italic=false, Bold=true} -- preprocessed strings (printf, echo)

-- key words
Keywords={
	{Colour=base0D, Italic=false, Bold=true}, -- section headers
	{Colour=base05, Italic=false, Bold=true}, -- '_'
	{Colour=base04, Italic=false, Bold=false}, -- deprecated, keep bold false, '<...>'
	{Colour=base06, Italic=false, Bold=true}, -- '▪', '▸' and '•'
	{Colour=base0E, Italic=false, Bold=true}, -- '[...]'
	{Colour=base0F, Italic=false, Bold=true}, -- '$(...)' '${...}'
}

-- semantic tokens
SemanticTokenTypes={
	{Type='class',Style={Colour=base0A}},  -- class names
	{Type='enumMember',Style=Keywords[5]}, -- enum members
	--{Type='function',Style=Keywords[4]}, -- function names
	{Type='interface',Style={Colour=base06}}, -- interface names
	--{Type='keyword',Style=Keywords[4]}, -- keyword
	--{Type='method',Style=Keywords[4]}, -- method names
	{Type='number',Style=Number}, -- numeric values 
	{Type='operator',Style=Operator}, -- logic and arithmetic operators
	{Type='parameter',Style=Keywords[6]}, -- function or method args
	{Type='regexp',Style=String}, -- regular expressions
	{Type='struct',Style={Colour=base0A}}, -- user defned types
	{Type='type',Style=Keywords[2]}, -- data types
	{Type='variable',Style=Keywords[5]}, -- variable names
}
