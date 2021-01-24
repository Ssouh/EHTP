<h1> Bonjour 1GI </h1> 
<?php
	$a = array(12,true,"abc");
	$b = ['a'=>222 , 9=> true , "abc"=>'blabla'];
	$b['babla']='****';
	for ($i=0; $i<count($a);$i++)
		echo '<h2>'.$i.'=>'.$a[$i].'</h2>';
	foreach ($b as $key => $value) {
		echo "<h2 $key => $value </h2>";
	}
	?>
	<hr>

	<pre>
	<?php
	var_dump($a);
	print_r($a);
	$out = isset($a);
	echo '$a'  ($out ? "Existe" : "n'existe pas"); 
?>
</pre>


