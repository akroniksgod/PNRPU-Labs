var args = WScript.Arguments
if (args.length === 0) 
{
  WScript.Echo("Empty set!")
  WScript.Quit()
}

var min = Number(args(0))
for (var i = 1; i < args.length; i++) 
{
	if (Number(args(i)) < min && Number(args(i)) & 2 !== 0)
		min = Number(args(i))  
}

WScript.Echo("min = ", min);