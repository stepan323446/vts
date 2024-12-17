<?php
$error_message = false;
$result = false;
if(!empty($_POST['number_1']) && !empty($_POST['number_2']) && $_SERVER['REQUEST_METHOD'] == 'POST') {
    $num_1 = (float)$_POST['number_1'];
    $num_2 = (float)$_POST['number_2'];

    switch($_POST['operation']) {
        case 'add':
            $result = $num_1 + $num_2;
        break;

        case 'sub':
            $result = $num_1 - $num_2;
        break;

        case 'plural':
            $result = $num_1 * $num_2;
        break;

        case 'divide':
            $result = $num_1 / $num_2;
        break;
        
        default:
            $error_message = "Unexpected operation";
        break;
    }
        
}
else if($_SERVER['REQUEST_METHOD'] == 'POST') {
    $error_message = "You don't have some number";
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Zadatak</title>
</head>
<body>
    <form action="#" method="post">
        <fieldset>
            <legend>Digitron</legend>
            <label for="number_1">Prvi broj</label>
            <input type="number" name="number_1" id="number_1" value="<?php if(isset($_POST['number_1'])) echo $_POST['number_1'] ?>">

            <label for="operation">Operacija</label>
            <select name="operation" id="operation">
                <option value="add" default>+</option>
                <option value="sub" default>-</option>
                <option value="plural" default>X</option>
                <option value="divide" default>/</option>
            </select>

            <label for="number_2">Drugi broj</label>
            <input type="number" name="number_2" id="number_2" value="<?php if(isset($_POST['number_2'])) echo $_POST['number_2'] ?>">

            <button type="submit">Rezultat</button>
        </fieldset>
    </form>
    <?php if($result !== false): ?>
    <p>
        Result: <?php echo $result ?>
    </p>
    <?php endif; ?>

    <?php if($error_message !== false): ?>
    <p>
        Error: <?php echo $error_message ?>
    </p>
    <?php endif; ?>
</body>
</html>