# Cross domain webfont access
location ~* \.(?:ttf|ttc|otf|eot|woff)$ {
  add_header "Access-Control-Allow-Origin" "*";

  # Also, set cache rules for webfonts.
  #
  # See http://wiki.nginx.org/HttpCoreModule#location
  # And https://github.com/h5bp/server-configs/issues/85
  # And https://github.com/h5bp/server-configs/issues/86
  expires 1M;
  access_log off;
  add_header Cache-Control "public";
}