<!DOCTYPE html>
<html>
<head>
	<title>Adding a surname</title>
</head>
<body>
	<?php 
		include 'connect.php';	
		$request = "INSERT INTO `3_student` (`surname`) VALUES ('".$_GET[surname]."')";
		$bdd->query($request);	
	?>
	
	<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
	
</body>
</html>