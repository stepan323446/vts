<?php
$str0 = "0";
$str1 = "5";
$str2 = "3";
$str12 = $str1 + $str2;

$str = "Hello world";
// real string not working - error


?>
<h1>
    <?php 
    include_once "data.php";
    require_once "data.php";
    ?>
</h1>

<p>
    str1 "5" + str2 "3" = <?php var_dump($str12) ?>
</p>
<p>
    str1 "5" as int = <?php var_dump((int)$str1) ?>
</p>
<p>
    str "Hello world" as int = <?php var_dump((int)$str) ?>
</p>
<p>
    empty for 0 = <?php echo empty(0) ?>
</p>
<p>
    isset for $str0 = <?php echo isset($str0) ?>
</p>
<?php
// if str "0", its false
$result_with = ($str0 && true);
?>
<p>($str0 && true) = <?php var_dump($result_with) ?></p>

<?php
// if str "0", its false
$mynull = null;
?>
<p>isset($mynull) = <?php var_dump(value: isset($mynull)) ?></p>

<?php
// if str "0", its false
$zero_or_one = $str0 ?? $str1;
?>
<p>str0 ?? str1 = <?php var_dump($zero_or_one) ?></p>

<?php
$ternarni_if = ($str0 && $str1) ? "YES" : "NO";
?>
<p>($str0 && $str1) ? "YES" : "NO" = <?php var_dump($ternarni_if) ?></p>

<?php
$some_str1 = (int)"1.5Hello_World434";
$some_str2 = (float)"1.5Hello_World434";
?>
<p>(int)"1.5Hello_World434" = <?php var_dump($some_str1) ?></p>
<p>(float)"1.5Hello_World434" = <?php var_dump($some_str2) ?></p>

<?php
$arr = array(
    "name" => "Stepan",
    "lname" => "Turitsin"
);
?>
<p><?php var_dump($arr) ?></p>

<?php
$spaceship = 2 <=> 1;
?>
<p>
    2<=>1 = <?php var_dump($spaceship) ?>
</p>

<?php
$arr2 = [1, 2, 3, 4, 5];
$check = $arr2[5] ?? 1;
?>
<p>
$check = $arr2[5] ?? 1 = <?php var_dump($check) ?>
</p>
