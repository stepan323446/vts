<?php

$name = $_POST['name'];
$email = $_POST['email'];
$message = $_POST['message'];
?>

<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Success page</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.5/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-SgOJa3DmI69IUzQ2PVdRZhwQ+dy64/BUtbMJw1MZ8t5HZApcHrRKUc4W0kG879m7" crossorigin="anonymous">
  </head>
  <body>
    <div class="container">
    <div class="alert alert-success" role="alert">
        <h4 class="alert-heading">Well done!</h4>
        <p>We have successfully received your message. Thank you for contacting us</p>
        <hr>
        <div>
            <p>Your data:</p>
            <ul>
                <li><b>Name: </b> <?php echo $name ?></li>
                <li><b>Email: </b> <?php echo $email ?></li>
                <li><b>Message: </b> <?php echo $message ?></li>
            </ul>
        </div>
    </div>
    </div>  

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.5/dist/js/bootstrap.bundle.min.js" integrity="sha384-k6d4wzSIapyDyv1kpU366/PK5hCdSbCRGRCMv+eplOQJWyd1fbcAu9OCUj5zNLiq" crossorigin="anonymous"></script>
  </body>
</html>