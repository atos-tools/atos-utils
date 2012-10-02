import os

coverage_enabled = (
    bool(os.getenv("ATOS_COVERAGE_DIR")) or bool(os.getenv("ATOS_COVERAGE")))

if coverage_enabled:
    import coverage

    if os.getenv("ATOS_COVERAGE_DIR"):
        coverage_dir = os.getenv("ATOS_COVERAGE_DIR")
        coverage_file = os.path.join(
            coverage_dir, ".coverage.%d" % (os.getpid()))
    else:
        coverage_file = ".coverage"
    cov = coverage.coverage(data_file=coverage_file, auto_data=True)
    cov.start()
