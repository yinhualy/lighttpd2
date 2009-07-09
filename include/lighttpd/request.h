#ifndef _LIGHTTPD_REQUEST_H_
#define _LIGHTTPD_REQUEST_H_

#ifndef _LIGHTTPD_BASE_H_
#error Please include <lighttpd/base.h> instead of this file
#endif

struct liRequestUri {
	GString *raw;

	GString *scheme;
	GString *authority;
	GString *path, *orig_path;
	GString *query;

	GString *host; /* without userinfo and port */
};

struct liPhysical {
	GString *path;
	GString *basedir;

	GString *doc_root;
	GString *rel_path;

	GString *pathinfo;

	gboolean have_stat;
	gboolean have_errno;
	guint stat_errno;
	struct stat stat; /* contains valid data only if have_stat is true */
};

struct liRequest {
	liHttpMethod http_method;
	GString *http_method_str;
	liHttpVersion http_version;

	liRequestUri uri;

	liHttpHeaders *headers;
	/* Parsed headers: */
	goffset content_length;
};

LI_API void li_request_init(liRequest *req);
LI_API void li_request_reset(liRequest *req);
LI_API void li_request_clear(liRequest *req);

LI_API gboolean li_request_validate_header(liConnection *con);

LI_API void li_physical_init(liPhysical *phys);
LI_API void li_physical_reset(liPhysical *phys);
LI_API void li_physical_clear(liPhysical *phys);

#endif
