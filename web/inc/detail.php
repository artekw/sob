<?
/* sOB - Simple Open builing Bot
 *
 * Copyright 2009 - Claudio Mignanti <c.mignanti@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
*/
function loader() {

$fname = $_GET['file'];
$verb = $_GET['verb'];

$delta = (isset($verb) ? $verb : 5 ) * 1024;
//$delta = ( $delta < 1) ? 1 : $delta;

$fp = fopen("../log/" . $fname, "r");

$stat = fstat($fp);
$r = "Verbose: <a href=\"?page=detail&file=$fname&verb=". ($verb+1) ."\">+</a> <a href=\"?page=detail&file=$fname&verb=". ($verb-1) ."\">-</a></br>";
$r .= "File dimension: " . $stat["size"] . "</br>";
$r .= "Last change: " . $stat["mtime"] . "</br>";

$r .= "<pre>";

//Stampa solo l'ultimo 1KB

$star = $stat["size"] - $delta;
if ( $star < 0 )
	$star = 0;

fseek($fp, $star);

$r .= fread($fp,$delta);
fclose($fp);

$r .= "</pre>";

return $r;
}

?>
