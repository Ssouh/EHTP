<?php
session_start();

if(!isset($_SESSION['panier']))
    $_SESSION['panier'] = [];
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Commerce</title>
</head>
<body>
<h1>produits</h1>
<table border="1" width="100%">
    <tr>
        <th>ref</th>
        <th>désignation</th>
        <th>Quantité</th>
        <th>Prix</th>
    </tr>
    <tr id="ref_1">
        <td>1</td>
        <td>TV 54pouces</td>
        <td><input type="text"  value="1"> </td>
        <td> 3450.00 </td>
        <td><button onclick="ajouter(1)">Ajouter</button></td>
    </tr>
    <tr id="ref_2">
        <td>2</td>
        <td>DVR 54Go</td>
        <td><input type="text" value="1"> </td>
        <td> 4050.00 </td>
        <td><button onclick="ajouter(2)">Ajouter</button></td>
    </tr>
    <tr id="ref_3">
        <td>3</td>
        <td>Camera 24Mp</td>
        <td><input type="text"  value="1"> </td>
        <td> 2950.00 </td>
        <td><button onclick="ajouter(3)">Ajouter</button></td>
    </tr>
    <tr id="ref_4">
        <td>4</td>
        <td>Scanner 3600dpi</td>
        <td><input type="text"  value="1"> </td>
        <td> 1350.00 </td>
        <td><button onclick="ajouter(4)">Ajouter</button></td>
    </tr>
</table>
<script>
    function ajouter(ref) {
        var qte = document.querySelector('#ref_' + ref + ' input').value
        location.href = "panier.php?ref=" + ref + "&qte=" + qte;

    }
</script>
<hr>
<pre>
    <?php print_r($_SESSION); ?>
</pre>
</body>
</html>