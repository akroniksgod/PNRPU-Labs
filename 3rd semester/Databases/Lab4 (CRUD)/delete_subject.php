<!DOCTYPE html>
<html>
<head>
	<title>Deleting a subject</title>
</head>
<body>
	<?php 
		include 'connect.php';	
		$request = "DELETE FROM `3_subject` WHERE `3_subject`.`code_of_subject` = ".$_GET[code_of_subject]."";		
		$bdd->query($request);	
	?>
	<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
</body>
</html>	