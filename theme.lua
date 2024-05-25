-- General
Description="h3lp"
Categories={"dark", "base16", "lsp"}

-- Palette
base00="#101010" -- Black
base01="#ff40ff" -- Pink
base02="#e10000" -- Red
base03="#c6c6ac" -- Grey Yellow
base04="#ffffff" -- Grey
base05="#0cd019" -- Ill Green
base06="#008436" -- Sexy Green
base07="#8cfe6b" -- Green
base08="#5d00c3" -- Dark Purple
base09="#58c485" -- Turquoise
base0A="#ffffff" -- White
base0B="#caaaff" -- Purple
base0C="#b42fea" -- Hard Purple
base0D="#baff29" -- Hard Green
base0E="#006cd2" -- Hard Blue
base0F="#194f19" -- Dark Green

-- Text Types
BlockComment={Colour=base03, Italic=true, Bold=true} -- Multi Line Comments
Canvas={Colour=base00, Italic=false, Bold=true} -- Default Background
Default={Colour=base06, Italic=false, Bold=true} -- Default Foreground Text
Escape={Colour=base0C, Italic=false, Bold=true} -- Escape Sequenced Strings
Interpolation={Colour=base09, Italic=false, Bold=true} -- Interpolated Strings (Placeholders)
LineComment={Colour=base03, Italic=true, Bold=false} -- Single Line Comment Blocks
LineNum={Colour=base0E, Italic=false, Bold=false} -- Line Numbers
Number={Colour=base09, Italic=false, Bold=true} -- Numeric Values
Operator={Colour=base06, Italic=false, Bold=true} -- Logic And Arithmetic Operators
PreProcessor={Colour=base0F, Italic=false, Bold=true} -- Deprecated
String={Colour=base05, Italic=false, Bold=true} -- Regular Expressions
StringPreProc={Colour=base0C, Italic=false, Bold=true} -- Preprocessed Strings (Printf, Echo)

-- Key Words
Keywords={
    {Colour=base0D, Italic=false, Bold=true}, -- Section Headers
    {Colour=base05, Italic=false, Bold=true}, -- '_'
    {Colour=base04, Italic=false, Bold=false}, -- Deprecated, Keep Bold False, '<...>'
    {Colour=base06, Italic=false, Bold=true}, -- '▪', '▸' And '•'
    {Colour=base0E, Italic=false, Bold=true}, -- '[...]'
    {Colour=base0F, Italic=false, Bold=true}, -- '$(...)' '${...}'
}

-- Semantic Tokens
SemanticTokenTypes={
    {Type='class',Style={Colour=base0A}},  -- Class Names
    {Type='enumMember',Style=Keywords[5]}, -- Enum Members
    --{Type='function',Style=Keywords[4]}, -- Function Names
    {Type='interface',Style={Colour=base06}}, -- Interface Names
    --{Type='keyword',Style=Keywords[4]}, -- Keyword
    --{Type='method',Style=Keywords[4]}, -- Method Names
    {Type='number',Style=Number}, -- Numeric Values 
    {Type='operator',Style=Operator}, -- Logic And Arithmetic Operators
    {Type='parameter',Style=Keywords[6]}, -- Function Or Method Args
    {Type='regexp',Style=String}, -- Regular Expressions
    {Type='struct',Style={Colour=base0A}}, -- User Defined Types
    {Type='type',Style=Keywords[2]}, -- Data Types
    {Type='variable',Style=Keywords[5]}, -- Variable Names
}
