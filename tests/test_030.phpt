--TEST--
Ingres: Adjust the date format to FINNISH and retrieve a date value.
--SKIPIF--
<?php require_once('skipif.inc'); ?>
--ENV--
II_SYSTEM=/opt/Ingres/II
INGRES_DATE_FORMAT=INGRES_DATE_FINNISH
--FILE_EXTERNAL--
files/date_format_test.php
--EXPECT--
Connection succeeded.2005-09-06 12:00:00
