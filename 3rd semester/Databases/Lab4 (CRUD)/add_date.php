<!DOCTYPE html>
<html>
<head>
	<title>Adding a date</title>
</head>
<body>
	<?php 
		include 'connect.php';	
		$request = "INSERT INTO `3_exam` (`date_of_exam`) VALUES ('".$_GET[date_of_exam]."')";
		$bdd->query($request);	
	?>
	<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
</body>
</html>	