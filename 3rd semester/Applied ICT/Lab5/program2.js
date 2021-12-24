var args = WScript.Arguments
if (args.length === 0 || args.length % 2 !== 0) 
{
  WScript.Echo(args.length === 0 ? "Empty set!" : "The set should contain even count of elements")
  WScript.Quit()
}

var max = 0
var result = ""

for (var i = 0; i < args.length; i += 2) 
{
  var cur = Number(args(i))
  var nex = Number(args(i + 1))
  max = cur > nex ? cur : nex

  result += "max(" + cur + ", " + (nex) + ")= " + max + "\n"
}

WScript.Echo(result);