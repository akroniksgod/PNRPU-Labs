<?php 
	$mysqli = new mysqli("kdenisb.ru:23306", "stud20", "Zz8Gws4Vv", "stud20_TAZ");

	$stmt = $mysqli->prepare("INSERT INTO `5_fblob` (`fname`, `fdata`) VALUES(?,?)");

	$null = NULL;
	$stmt->bind_param("sb", $_FILES['myFile']['name'], $null);

	$stmt->send_long_data(1, file_get_contents($_FILES['myFile']['tmp_name']));

	$stmt->execute();

	$stmt->close();
	$mysqli->close();
	/*
	$bdd = new PDO('mysql:host=kdenisb.ru;port=23306;dbname=stud20_TAZ', "stud20", "Zz8Gws4Vv");
	$name = $_POST['myFile']['name'];

	$data = file_get_contents($_POST['myFile']['tmp_name']);
	$stmt = $bdd->prepare("INSERT INTO `5_fblob` (`fname`, `fdata`) VALUES(?,?)");
	$stmt = bindParam(1, $name);	
	$stmt = bindParam(2, $data, PDO::PARAM_LOB);	
	$stmt->exec();	

	$stmt->close();
	$data->delete();
	$bdd->close();
	*/
?>