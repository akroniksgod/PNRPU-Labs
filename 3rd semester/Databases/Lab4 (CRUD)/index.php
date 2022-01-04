<!DOCTYPE html>
<html>
  <head>
    <title></title>
     <style type="text/css">
       .visit {border: solid black 1px;}
		.edit, .del {float: center;}
     </style>
  </head>
  <body>

<?php
include 'connect.php';

include 'request.php';
/////////////////////////////////////////////////*READING*/////////////////////////////////////////////////
$result = $bdd->query($req);	 //'2021-09-20';

foreach($result as $row) 
{
?>
	<div class="visit">		
		<div class="surname"><?=$row["surname"]?></div>
		<div class="name"><?=$row["name"]?></div>
		<font style="font-size:0px"> - text 
			<div class ="id"><?=$row["id_exam"]?></div>
		</font>
		<div class="edit">
			<a href="upd.php?id_exam=<?=$row["id_exam"]?>&surname=<?=$row["surname"]?>&date_of_exam=<?=$_GET[date_of_exam]?>">Edit student</a>		
		</div>
		<div class="del">
			<a href="del.php?id_exam=<?=$row["id_exam"]?>&date_of_exam=<?=$_GET[date_of_exam]?>">Drop out of the date</a>
		</div>


	</div>
<?php
}
?>
<!--/////////////////////////////////////////////////*READING*/////////////////////////////////////////////////-->

<!--/////////////////////////////////////////*CREATING*/////////////////////////////////////////-->
<div class = "visit">
	<form action = "arrange.php">
		<select name = "code_of_report_card">
			<option>Choose Surname</option>
<?php

$result = $bdd->query($req2);
foreach($result as $row) 
{
?>			
			<option value="<?=$row["code_of_report_card"]?>"><?=$row["surname"]?></option>
<?php
}
?>
		</select>
		<select name = "code_of_subject">
			<option>Choose subject</option>
<?php

$result = $bdd->query($req4);
foreach($result as $row) 
{
?>
			<option value="<?=$row["code_of_subject"]?>"><?=$row["name"]?></option>
<?php
}
?>	
		</select>
		<select name = "date_of_exam">
			<option>Choose Date</option>
<?php
$result = $bdd->query($req3);
foreach($result as $row) 
{
?>			
			<option value="<?=$row["date_of_exam"]?>"><?=$row["date_of_exam"]?></option>
<?php
}
?>
		</select>
		<button>Make an arrangement</button>
	</form>
</div>
<!--/////////////////////////////////////////*CREATING*/////////////////////////////////////////-->


<!--//////////////////////////////////////*EDITING DICTIONARY*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-->
<div class = "visit">
	<br>Edit dictionary:</br>
	<form action = "add_surname.php" method = "get">
 		New surname:<input type="text" size="20" name = "surname">			
			<input type = "hidden" name = "date_of_exam" value = "<?=$_GET[date_of_exam]?>">
		<input type = "submit" value = "Create a surname"> 
	</form>
	<form action = "add_subject.php" method = "get">
 		
		New subject:  <input type="text" size="20" name = "name">		
		<input type = "hidden" name = "date_of_exam" value = "<?=$_GET[date_of_exam]?>">
		<input type = "submit" value = "Create a subject">
	</form>
	<form action = "add_date.php" method = "get">
 		New date:  <input type="date" name = "date_of_exam">	
		<button>Create a date</button>
	</form>

	<br><form action = "delete_surname.php" method = "get">
Choose the surname to delete:
		
			<select name = "code_of_report_card">			
			<option>Choose Surname</option>
<?php

$result = $bdd->query($req2);
foreach($result as $row) 
{
?>			
			<option value="<?=$row["code_of_report_card"]?>"><?=$row["surname"]?></option>
<?php
}
?>
		</select>
	<input type = "hidden" name = "date_of_exam" value = "<?=$_GET[date_of_exam]?>">
	<input type = "submit" value = "Delete">
</br>

	</form>
	<form action = "delete_subject.php" method = "get">
	Choose the subject to delete:
			<select name = "code_of_subject">
			<option>Choose subject</option>
<?php

$result = $bdd->query($req4);
foreach($result as $row) 
{
?>
			<option value="<?=$row["code_of_subject"]?>"><?=$row["name"]?></option>
<?php
}
?>	
		</select>
		<input type = "hidden" name = "date_of_exam" value = "<?=$_GET[date_of_exam]?>">
		<input type = "submit" value = "Delete">
	</form>
	<form action = "delete_date.php" method = "get">
Choose the date to delete:
					<select name = "id_exam">
			<option>Choose Date</option>
<?php
$result = $bdd->query($req3);
foreach($result as $row) 
{
?>			
			<option value="<?=$row["id_exam"]?>"><?=$row["date_of_exam"]?></option>
<?php
}
?>
		</select>

			<input type = "hidden" name = "date_of_exam_to_return" value = "<?=$_GET[date_of_exam]?>">
		<input type = "submit" value = "Delete">
	</form>

</div>
<!--//////////////////////////////////////*EDITING DICTIONARY*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-->

<a href="./crud.php">Choose another date</a>
  </body> 
</html> 
