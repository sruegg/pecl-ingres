--TEST--
Ingres: Adjust the timezone to GMT and retrieve a date value.
--SKIPIF--
<?php require_once('skipif.inc'); ?>
--ENV--
II_SYSTEM=/opt/Ingres/II
INGRES_TIMEZONE=GMT
--FILE_EXTERNAL--
files/timezone_test.php
--EXPECT--
Connection succeeded.06-sep-2005 12:00:00
