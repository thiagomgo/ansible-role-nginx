## The X-Frame-Options HTTP response header is normally used to indicate if a browser
## should be allowed to render a page in a <frame> or an <iframe>
add_header X-Frame-Options "SAMEORIGIN";

# Only allow these request methods ##
if ($request_method !~ ^(GET|HEAD|POST)$ ) {
	return 444;
}

# Block download agents ##
if ($http_user_agent ~* LWP::Simple|BBBike|wget) {
  return 403;
}

# Block some robots ##
if ($http_user_agent ~* msnbot|scrapbot) {
  return 403;
}

# Block access to hidden files and directories.
# This includes directories used by version control systems such as Git and SVN.
location ~* (?:^|/)\. {
  deny all;
  access_log off;
  log_not_found off;
}

# Block access to backup and source files.
# These files may be left by some text editors and can pose a great security
# danger when anyone has access to them.
location ~* (?:\.(?:bak|config|sql|fla|psd|ini|log|sh|inc|swp|dist)|~)$ {
  deny all;
  access_log off;
  log_not_found off;
}

# No other scripts
location ~* \.(pl|cgi|py|sh|lua)\$ {
    return 444;
}