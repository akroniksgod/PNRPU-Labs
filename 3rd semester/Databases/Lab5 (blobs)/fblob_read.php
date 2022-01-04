<?php
	$mysqli = new mysqli("kdenisb.ru:23306", "stud20", "Zz8Gws4Vv", "stud20_TAZ");

	$statement = $mysqli->prepare("SELECT `fdata` FROM `5_fblob` WHERE `id` = ?");

	$id = 5;

	$statement->bind_param("i", $id);

	$statement->execute();

	$statement->store_result();

	$statement->bind_result($audio);

	$statement->fetch();

	header("Content-Type: audio/ogg");

	echo $audio;
?>