Dim  Alphabet, N(100)
Dim i, length, sum
Alphabet = InputBox("Enter numbers and split them with space (only positive digits)","Odd digits sum")
length = Len(Alphabet)

For i = 1 To length
	N(i - 1) = Mid(Alphabet, i, 1)
	
	If (N(i - 1) <> " ")  Then
		If (N(i - 1) mod 2 <> 0) Then
			sum = sum + CInt(N(i - 1))
		End If
	End If
Next

MsgBox sum, 0, "Odd digits sum"