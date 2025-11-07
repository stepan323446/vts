<?php 
require_once("functions.php");
require_once("config.php");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Zadatak</title>

    <style>
        .question {
            margin-bottom: 20px;
        }
    </style>
</head>
<body>
    <h1>Zadatak 1</h1>
    <div class="question">
        <?php
        $monthKeySelect = new SelectArray(
            "key_months", 
            "key_months", 
            "Month: ", 
            $months, 
            true);
        $monthKeySelect->setDefaultValue(3);
        $monthKeySelect->render();
        ?>
        <p>Default value is Mart</p>
    </div>
    <div class="question">
        <?php
        $monthValueSelect = new SelectArray(
            "value_months", 
            "value_months", 
            "Month: ", 
            $months, 
            false);
        $monthValueSelect->setDefaultValue("April");
        $monthValueSelect->render();
        ?>
        <p>Default value is April</p>
    </div>
    <div class="question">
        <?php
        $ageSelectOne = new SelectNumber(
            "age_one",
            "age_one",
            "Age: ",
            32,
            13
        );
        $ageSelectOne->render();
        ?>
    </div>
    <div class="question">
        <?php
        $ageSelectTwo = new SelectNumber(
            "age_two",
            "age_two",
            "Age: ",
            10,
            52
        );
        $ageSelectTwo->setDefaultValue(20);
        $ageSelectTwo->render();
        ?>
    </div>
    
</body>
</html>