<?php 
session_start();
$type=$_GET['type'];

$dsn='mysql:host=localhost;dbname=ecom;charset=utf8';
$user="root";
$password="";

$db = new PDO($dsn,$user,$password);
$db->setAttribute(PDO::ATTR_CASE,PDO::CASE_LOWER);// les noms de champs seront en miniscules

$s =$db->prepare("SELECT * FROM produits  WHERE type LIKE '$type'");
$s->execute();
$Res=$s->fetchAll(PDO::FETCH_ASSOC)
//print_r($Res);
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" type="text/css" media="screen" href="node_modules/bootstrap/dist/css/bootstrap.css" />
    <link rel="stylesheet" href="style.css" />
    <title>Document</title>
</head>
<body>
<nav class="navbar navbar-expand-sm navbar-light bg-light">
        <a class="navbar-brand" >EHTP E-Commerce</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
      
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
          <ul class="navbar-nav mr-auto">
            <li class="nav-item active">
              <a class="nav-link" href="index.php">Home <span class="sr-only">(current)</span></a>
            </li>
            <?php 
            $dsn='mysql:host=localhost;dbname=ecom;charset=utf8';
            $user="root";
            $password="";
            $db = new PDO($dsn,$user,$password);
            $s =$db->prepare("SELECT * FROM produits  WHERE type LIKE 'veston' "); $s->execute();
            ?>
            <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                      Catégories
                    </a>
                    <div class="dropdown-menu" aria-labelledby="navbarDropdown">
                      <a class="dropdown-item" href="produits.php?type=blouson">Blouson</a>
                      <a class="dropdown-item" href="produits.php?type=chemise">Chemise</a>
                      <a class="dropdown-item" href="produits.php?type=veston">Veston</a>
                    </div>
                  </li>
          </ul>
        </div>
      </nav>
<div class="row" class="box1">
<?php foreach ($Res as $row) :?>
<div class="card" style="width:18rem;">
  <img src="./images/<?= $row['photo'] ?>" class="card-img-top" alt="...">
  <div style="text-align:center " class="card-body">
    <h5 class="card-title"><?= $row['designation'] ?></h5>
      <?php
          $p = $row['prixpromo'];

          if ($p == 0) :?>
            <p class="card-text"><?= $row['prixnormal'] ?>$ </p><br>
          <?php else :?>
            <p class="card-text"><strike><?= $row['prixnormal'] ?>$</strike>  <?= $row['prixpromo'] ?>$</p><br>
        <?php endif; ?>
    <a href="panier.php?ref=<?= $row['reference'] ?>&type=<?= $_GET['type']?>" class="btn btn-primary">Ajouter au panier</a>
    </div>
  </div>
  <?php endforeach; ?>
</div>
<script src="node_modules/jquery/dist/jquery.min.js"></script>
    <script src="node_modules/popper.js/dist/umd/popper.min.js"></script>
    <script src="node_modules/bootstrap/dist/js/bootstrap.min.js"></script>
</body>
</html>