<?php
require_once("user.php");

$steve_dekart = new User(
    "steve_dekart",
    "Stepan",
    "Turitsin",
    "stevedekart@yandex.ru",
    21,
    "Visoka Tehnička škola",
    ["PHP", "Nuxt", "Django"],
);
$greendavid = new User(
    "greendavid004",
    "David",
    "Katrinka",
    "davidkatrinka@gmail.com",
    21,
    "Visoka Tehnička škola",
    ["PHP", "Android Studio", "Arduino"]
);

/**
 * @var User[] $users
 */
$users = [
    $steve_dekart,
    $greendavid
]
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Task 1</title>
    <style>
        .user p {
            font-weight: 600;
        }
        .user td {
            padding: 5px;
        }
    </style>
</head>
<body>
    <h2>Task 1</h2>
    <?php foreach($users as $user): ?>
    <div class="user">
        <h3><?= htmlspecialchars($user->getName()) ?></h3>
        
        <?php $user->showUserData() ?>

        <p>Skills:</p>
        <?php $user->showSkills() ?>
        
        <p>Validate email (x1)</p>
        <?= $user->validateEmail() ?>

        <p>Validate email (x2)</p>
        <?php $user->setEmail("somewrongmail") ?>
        <?= $user->validateEmail() ?>
        <hr>
    </div>
    <?php endforeach; ?>
</body>
</html>