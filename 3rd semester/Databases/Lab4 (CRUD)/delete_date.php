<!DOCTYPE html>
<html>
<head>
	<title>Deleting a date</title>
</head>
<body>
	<?php 
		include 'connect.php';	
		$request = "DELETE FROM `3_exam` WHERE `3_exam`.`id_exam` = ".$_GET[id_exam]."";		
		$bdd->query($request);	
	?>
	<a href="./?date_of_exam=<?=$_GET[date_of_exam_to_return]?>">Return</a>
</body>
</html>	