import os
import pathlib
import shutil

import nox

ROOT = pathlib.Path(__file__).parent


@nox.session
def lint(session: nox.Session) -> None:
    """Look for lint."""
    session.install("pre-commit")
    session.run("pre-commit", "run", "--all-files")


@nox.session(name="build-docs")
def build_docs(session: nox.Session) -> None:
    """Build the docs."""
    docs_dir = ROOT / "docs"
    build_dir = docs_dir / "build"

    session.install("sphinx>=4")

    build_dir.mkdir(exist_ok=True)
    session.run(
        "sphinx-build",
        "-b",
        "html",
        "-W",
        "--keep-going",
        docs_dir / "source",
        build_dir / "html",
    )
    session.log(f"generated docs at {build_dir / 'html'!s}")


@nox.session(python=False, name="clean-docs")
def clean_docs(session: nox.Session) -> None:
    """Clean up the docs folder."""
    build_dir = ROOT / "docs" / "build"

    if (build_dir / "html").is_dir():
        with session.chdir(build_dir):
            shutil.rmtree("html")

    if (ROOT / "build").is_dir():
        session.chdir(ROOT / "build")
        if os.path.exists("html"):
            shutil.rmtree("html")


@nox.session(python=False)
def nuke(session):
    """Run all clean sessions."""
    clean_docs(session)
