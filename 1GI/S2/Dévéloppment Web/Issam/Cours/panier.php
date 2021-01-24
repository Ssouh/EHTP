<?php

$ref = $_GET['ref'];
$qte = $_GET['qte'];

session_start();

$_SESSION['panier'][$ref] = $qte;

header("location:com.php");