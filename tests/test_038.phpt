--TEST--
Ingres: test support for INTEGER8 values
--SKIPIF--
<?php require_once('skipif.inc'); ?>
--ENV--
II_SYSTEM=/opt/Ingres/IngresR3
--FILE--
<?php

require_once('connection.inc');

$conn=ingres_connect($database,$user,$password);

if ( ingres_errno($conn) ) {
	$error_code=ingres_errno();
	$error_text=ingres_error();
	$error_sqlstate=ingres_errsqlstate();
	printf ( "Error during connect : %s\n\r",$error_code);
	printf ( "Error during connect : %s\n\r", $error_text);
	printf ( "Error during connect : %s\n\r", $error_sqlstate);
	die("i died");
} 
else
{
	echo "Connection succeeded.";
}
$rc=ingres_query($conn,"select int8(9223372036854775806) as pos_int8, int8(-9223372036854775806) as neg_int8");

if ( ingres_errno() ) {
	$error_code=ingres_errno($conn);
	$error_text=ingres_error($conn);
	$error_sqlstate=ingres_errsqlstate($conn);
	printf ( "Error during query : %s\n\r",$error_code);
	printf ( "Error during query : %s\n\r", $error_text);
	printf ( "Error during query : %s\n\r", $error_sqlstate);
	die("i died");
} 
else
{
	while ( $object = ingres_fetch_object ($rc) ) {
		echo $object->pos_int8;
        echo " ";
		echo $object->neg_int8;
	}
}

ingres_close($conn);
?>
--EXPECT--
Connection succeeded.9223372036854775806 -9223372036854775806
