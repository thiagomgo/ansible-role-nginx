# Block access to xmlrpc file
location = /xmlrpc.php {
  deny all;
  log_not_found off;
  access_log off;
} 

# No php scripts in the upload directory
location ~* /(?:uploads|files)/.*\.php$ {
	deny all;
}

# Restrict WordPress pain points
location ~ /(wp-config.php|wp-comments-post.php|readme.html|license.txt) {
	deny all;
}

# Allow only internal access to .php files inside wp-includes directory
location ~* ^/wp-includes/.*\.(php|phps)$ {
	internal;
}