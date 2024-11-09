extensions = [
    "myst_parser",
    "sphinx.ext.intersphinx",
    "sphinx.ext.todo",
    "sphinx.ext.imgmath",
    "sphinx.ext.viewcode",
    "sphinx_design",
]

source_suffix = ".md"
master_doc = "index"
project = "bmi"
copyright = "2021, Community Surface Dynamics Modeling System"
author = "Community Surface Dynamics Modeling System"
version = "2.0"  # The short X.Y version.
release = "2.0"  # The full version, including alpha/beta/rc tags.
language = "en"
exclude_patterns = ["links.md"]
pygments_style = "sphinx"
pygments_dark_style = "monokai"
todo_include_todos = True

# -- Options for HTML output ----------------------------------------------

html_theme = "furo"
html_theme_options = {
    "announcement": None,
    "source_repository": "https://github.com/csdms/bmi/",
    "source_branch": "develop",
    "source_directory": "docs/source",
    "sidebar_hide_name": True,
    "footer_icons": [
        {
            "name": "power",
            "url": "https://csdms.colorado.edu",
            "html": """
                <svg
                  stroke="currentColor"
                  fill="currentColor"
                  stroke-width="0"
                  version="1.1"
                  viewBox="0 0 16 16"
                  height="1em"
                  width="1em"
                  xmlns="http://www.w3.org/2000/svg"
                >
                  <path
                    d="M6 0l-6 8h6l-4 8 14-10h-8l6-6z"
                  ></path>
                </svg>
                <b><i>Powered by CSDMS</i></b>
            """,
            "class": "",
        },
    ],
}
html_logo = "_static/bmi-logo.svg"
html_static_path = ["_static"]

intersphinx_mapping = {"python": ("https://docs.python.org/3", None)}

myst_enable_extensions = ["colon_fence", "deflist"]
