var args = WScript.Arguments
if (args.length === 0) 
{
  WScript.Echo("Empty set!")
  WScript.Quit()
}

var oddNum = []
for (var i = 0; i < args.length; i++) 
{
	oddNum[i] = Number(args(i))
}

var min = 0
var temp = 0
for (var i = 0; i < args.length - 1; i++) 
{
	min = i
	for (var j = i + 1; j < args.length; j++)
	{
		if (oddNum[min] > oddNum[j])
				min = j	
	}
	if (min !== i)
	{
		temp = oddNum[i]
		oddNum[i] = oddNum[min]
		oddNum[min] = temp
	}		
}

var cat = ""
for (var i = 0; i < args.length; i++) 
{
	if (oddNum[i] % 2 !== 0)
	{
		cat += oddNum[i] + "; "
	}		
}

WScript.Echo(cat);
