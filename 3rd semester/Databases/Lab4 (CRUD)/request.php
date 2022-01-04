<?php
$req = "SELECT `3_student`.`surname`, `3_subject`.`name`, `3_exam`.`id_exam` FROM `3_exam`
INNER JOIN `3_student` ON `3_student`.`code_of_report_card` = `3_exam`.`code_of_report_card` 
INNER JOIN `3_subject` ON `3_subject`.`code_of_subject` = `3_exam`.`code_of_subject`
WHERE `3_exam`.`date_of_exam` ='".$_GET[date_of_exam]."';";

$req2 = "SELECT `3_student`.`code_of_report_card` , `3_student`.`surname` FROM `3_student`";

$req3 = "SELECT `3_exam`.`id_exam` , `3_exam`.`date_of_exam` FROM `3_exam`";

$req4 = "SELECT `3_subject`.`code_of_subject` , `3_subject`.`name` FROM `3_subject`";
?>