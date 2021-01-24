
<?//php include("index.php");?>

<h2 style="text-align: center"> Votre Panier contient :</h2>

<?php

session_start();
if(!isset($_SESSION['panier']))
    $_SESSION['panier'] = [];
if(isset($_GET['ref'])):
    $ref=$_GET['ref'];

    $dsn='mysql:host=localhost;dbname=ecom;charset=utf8';
    $user="root";
    $password="";
    
    $db = new PDO($dsn,$user,$password);
    $db->setAttribute(PDO::ATTR_CASE,PDO::CASE_LOWER);// les noms de champs seront en miniscules
    
    $s =$db->prepare("SELECT distinct * FROM produits  WHERE Reference LIKE '$ref'");
    $s->execute();
    $Res=$s->fetchAll(PDO::FETCH_ASSOC);
    //print_r($Res);
$_SESSION['panier'][] = $Res;
endif;
// foreach($_SESSION['panier'] as $row=>$value)
// {
//    echo $value[0]['reference'];
// // print_r($value);
//     echo " ";
// }
?>

<link rel="stylesheet" type="text/css" media="screen" href="node_modules/bootstrap/dist/css/bootstrap.css" />
<link rel="stylesheet" href="style.css" />
<table class="table">
  <thead class="thead-dark">
    <tr>
      <th scope="col">#</th>
      <th scope="col">Type</th>
      <th scope="col">Designation</th>
      <th scope="col">Prix</th>
    </tr>
  </thead>
  <tbody>
      <?php foreach($_SESSION['panier'] as $row=>$value): if($_SESSION['panier'] != []):?>
        <tr>
        <th scope="row"><?= $row+1;?></th>
        <td><?= $value[0]['type'];?></td>
        <td><?= $value[0]['designation'];?></td>
        <td><?php $p = $value[0]['prixpromo'];
          if ($p == 0) : echo $value[0]['prixnormal'] ;
          else : echo $value[0]['prixpromo']; 
          endif; ?></td>
        </tr>
        <?php endif;?>
        <?php endforeach;?>
    </tbody>
</table>
<a type="button" href="index.php" class="btn btn-primary btn-lg btn-block">Retour aux Achats</a>
<a type="button" href="session.php" class="btn btn-primary btn-lg btn-block">Vider Panier</a><br><br>
