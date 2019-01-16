<html>
 
<body id="LoginForm">
<div class="container">
<h1 class="form-heading">login Form</h1>
<div class="login-form">
<div class="main-div">
    <div class="panel">
   <h2>Admin Login</h2>
   <p>Please enter your email and password</p>
   </div>
   <form  method='POST' action='/var/www/html/login.php' >	
		<p id="un">Username</p><br/>
		<input type="text" name="username" id="username" placeholder="Enter Username"required>

		<p id="pwd">Password</p><br/>
		<input type="password" name="password" id="password" placeholder="Enter Password" required>

		<span id="error" class="error"><?php echo $Error;?></span>

		<button type="submit"  name="login" id="login" >Login</button><br/>
	</form>	
    </div>
</div></div></div>


</body>
</html>

<?php

	$un = filter_input(INPUT_POST, 'username');
	$pwd = filter_input(INPUT_POST, 'password');

	if(!($un)){
		if(!($pwd)){

			$con = mysqli_connect("localhost","root","dell@123","login") ;
			if (mysqli_connect_errno()){
				echo "Failed to connect to MySQL: " . mysqli_connect_error();
			}

			else{
				$sql = "INSERT INTO pwd(username, password) values ($un, $pwd)";
			}
			if($con->query($sql)){
				echo "Hello $un";			
			}
			else{
				echo "Error: ". $sql ."<br>". $con->error;
			}

		}
		else{
			echo "Password should not be empty"
		}
	}
	else{
		echo "Username should not be empty";
	}
?>
