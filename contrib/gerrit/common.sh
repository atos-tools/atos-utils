
# Forge reviewer options to be passed to receive-pack
# Exclude user.email from actual reviewers
# Arg 1 is the default reviewers list
# Echoes the option list.
forge_reviewer_options() {
    local reviewers="${1?}"
    local user=`git config user.email | tr '[A-Z]' '[a-z]'`
    local reviewer_options=""
    local reviewer
    for reviewer in $reviewers; do
	if [ "$user" != "$reviewer" ]; then
	    reviewer_options="$reviewer_options --reviewer=$reviewer"
	fi
    done
    echo "$reviewer_options"
}

# Forge the remote parameter for the git push command.
# If the first arg is an existing remote, use it,
# otherwise returns the second argument
# Echoes the result parameter.
forge_remote_parameter() {
    local remote="${1?}"
    local default="${2?}"
    git remote show "$remote" >/dev/null 2>&1 || remote="$default"
    echo "$remote"
}

