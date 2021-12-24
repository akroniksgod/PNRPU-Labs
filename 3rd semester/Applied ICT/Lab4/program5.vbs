set args = WScript.Arguments

if args.count = 0 then
  MsgBox "No params entered!", 16, "Error"
  set args = nothing
  WScript.Quit
end if

dim min, task, j
task = "Even arguments = "

j = 0
dim len

dim evenNum(100)

For i = 0 To args.count() - 1
	evenNum(i) = CInt(args(i))
Next

For i = 0 To args.count() - 2
	min = i 
	For j = i + 1 To args.count() - 1
		If evenNum(min) > evenNum(j) Then
			min = j
		End If
	Next
	If (min <> j) Then
		temp = evenNum(i)
		evenNum(i) = evenNum(min)
		evenNum(min) = temp		
	End If
Next

cat = ""
For i = 0 to args.count() - 1
	If (CInt(evenNum(i)) mod 2 = 0) Then
		cat = cat & CInt(evenNum(i)) & "; " 
	End If
Next

MsgBox task & cat, 64, "Solution"