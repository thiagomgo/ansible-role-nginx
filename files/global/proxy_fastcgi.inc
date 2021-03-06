fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
include /etc/nginx/fastcgi_params;
fastcgi_split_path_info ^(.+\.php)(.*)$;
fastcgi_cache_bypass $cookie_nocache  $arg_nocache$arg_comment;
fastcgi_cache_bypass $http_pragma     $http_authorization;
fastcgi_cache_key $http_cookie$request_method$host$request_uri;
fastcgi_index index.php;
fastcgi_intercept_errors        on;
fastcgi_ignore_client_abort     on;
fastcgi_connect_timeout 60;
fastcgi_send_timeout 180;
fastcgi_read_timeout 180;
fastcgi_buffer_size 8192k;
fastcgi_buffers 4 8192k;
fastcgi_busy_buffers_size 8192k;
fastcgi_temp_file_write_size 8192k;
