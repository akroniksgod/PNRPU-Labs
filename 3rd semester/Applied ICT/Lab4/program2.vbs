set args = WScript.Arguments

if args.count = 0 then
  MsgBox "No params entered!", 16, "Error"
  set args = nothing
  WScript.Quit
end if

dim max, task
task = "Max even argument = "

max = CInt(args(0))
For i = 1 to args.count() - 1
	If (CInt(args(i)) mod 2 = 0 And CInt(args(i)) > max) Then
		max = CInt(args(i))
	End If
Next

MsgBox task & max, 64, "Solution"