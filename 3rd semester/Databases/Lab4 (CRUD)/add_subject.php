<!DOCTYPE html>
<html>
<head>
	<title>Adding a subject</title>
</head>
<body>
	<?php 
		include 'connect.php';	
		$request = "INSERT INTO `3_subject` (`name`) VALUES ('".$_GET[name]."')";
		$bdd->query($request);	
	?>
	<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
</body>
</html>	