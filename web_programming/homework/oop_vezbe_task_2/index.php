<?php
declare(strict_types=1);

require_once("user.php");
require_once("advanced_user.php");

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
$mihail_001 = new AdvancedUser(
    "mihail_001",
    "Mihail",
    "Romanov",
    "mihail_007@gmail.com",
    32,
    "Visoka Tehnička škola",
    ["JavaScript", "Java"],
    "https://github.com/stepan323446"
);

/**
 * @var (User|AdvancedUser)[] $users
 */
$users = [
    $steve_dekart,
    $greendavid,
    $mihail_001
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
    <h2>Task 2 (Count users: <?= User::getUserCount() ?>)</h2>
    <?php foreach($users as $user): ?>
    <div class="user">
        <h3><?= htmlspecialchars($user->getName()) ?></h3>
        
        <?php $user->showUserData() ?>

        <p>Skills:</p>
        <?php $user->showSkills() ?>
        
        <p>Validate email</p>
        <?= $user->validateEmail() ?>

        <?php if($user instanceof AdvancedUser): ?>
        <p>Github profile:</p>
        <p>
            <a href="<?= htmlspecialchars($user->getGithubProfile()) ?>">
                <?= htmlspecialchars($user->getGithubProfile()) ?>
            </a>
        </p>
        <?php endif; ?>
        <hr>
    </div>
    <?php endforeach; ?>
</body>
</html>