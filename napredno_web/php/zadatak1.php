<?php
function hello() 
{
    echo "Hello from VTŠ!";
}
function goodbye() 
{
    echo "Goodbye from VTŠ!";
}
function info($name, $year)
{
    $text = <<< EOT
Name: $name;
Year: $year;
EOT;
    echo $text;
}

$func = 'hello';
$func();
$nowdoc = <<< 'EOT'

$language = "PHP";
$number = 10;
$languages['PHP'] = 7;
$languages['CSS'] = 3;

$numbers[0][0] = 12;
$numbers[0][1] = 21;
EOT;

info("Stepan", 2003);