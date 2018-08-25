<?php
// The MIT License (MIT)
// Copyright (c) 2015 David Kevork
//  Permission is hereby granted, free of charge, to any person obtaining a 
//  copy of this software and associated documentation files (the "Software"), 
//  to deal in the Software without restriction, including without limitation 
//  the rights to use, copy, modify, merge, publish, distribute, sublicense, 
//  and/or sell copies of the Software, and to permit persons to whom the 
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in 
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
//  DEALINGS IN THE SOFTWARE.
function capture() {
	$protocol = (isset($_SERVER['HTTPS']) && strtolower($_SERVER['HTTPS']) == 'on') ? 'https://' : 'http://';
	$REQUEST_URI = explode("?", $_SERVER['REQUEST_URI']);
	$data = explode(".", $REQUEST_URI[0]);
	if (sizeof($data) > 1) // no extension
	{
		$ext = $data[count($data)-1];
		if ($ext == 'php') {
			$DomainName = $protocol.$_SERVER['SERVER_NAME'];
			$FileName = $data[0];
			for ($i = 1; $i < sizeof($data)-1; $i++) {
				$FileName .= '.'.$data[$i];
			}
			$Param = '';
			if (isset($REQUEST_URI[1])) {
				$Param = '?'.$REQUEST_URI[1];
			}
			$Location = $DomainName.$FileName.$Param;
			header("Location: $Location");
		}
	}
}
?>