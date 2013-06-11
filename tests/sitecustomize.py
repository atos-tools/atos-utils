import os, atexit

coverage_enabled = (
    bool(os.getenv("ATOS_COVERAGE_DIR")) or bool(os.getenv("ATOS_COVERAGE")))

if coverage_enabled:
    import coverage

    def cov_stop():
        cov.stop()
        cov.save()

    if os.getenv("ATOS_COVERAGE_DIR"):
        coverage_dir = os.getenv("ATOS_COVERAGE_DIR")
        coverage_file = os.path.join(coverage_dir, ".coverage")
    else:
        coverage_file = ".coverage"
    cov = coverage.coverage(
        data_file=coverage_file,
        data_suffix=True,
        branch=True)
    cov.start()
    atexit.register(cov_stop)
