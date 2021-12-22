set args = WScript.Arguments

if args.count = 0 then
  MsgBox "No params entered!", 16, "Error"
  set args = nothing
  WScript.Quit
end if

dim min, task
task = "Min even argument = "

min = CInt(args(0))
For i = 1 to args.count() - 1
	If (CInt(args(i)) mod 2 = 0 And min > CInt(args(i))) Then
		min = CInt(args(i))
	End If
Next

MsgBox task & min, 64, "Solution"