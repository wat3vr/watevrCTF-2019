# Challenge format

Any directory in this directory with a `challenge.json` file will be counted as a challenge directory. It would be great to sort challenges by category, so for example if you are making a web challenge called challenge1 save it in `/challenges/web/challenge1/`.

## challenge.json format

```json
{
    "flag": "some_flag",
    "append_random_data": true,
    "follows_flag_format": true,
    "categories": [
        "reversing",
        "web"
    ],
    "authors": ["mateuszdrwal"],
    "title": "some web and reversing challenge",
    "description": "this is the challenge description",
    "uses_docker": true,
    "website_services": [
        80
    ],
    "netcat_services": [
        50000
    ],
    "build_script": "python build.py",
    "solve_script": "python solve.py",
    "changeable_flag": true,
    "unlocked_by": null,
}
```

field clarifications:

- `flag`: The raw flag for the challenge, it will be surrounded by the flag format automatically.
- `append_random_data`: If a few random characters should be appended to the flag for guess prevention, like `_ad74j`
- `follows_flag_format`: If the flag follows the typical flag format or not
- `categories`
- `authors`: Array of challenge authors
- `title`
- `description`: (markdown allowed)
- `uses_docker`: If this challenge uses a service like a website, which is required to be provided by a docker container.
- `website_services`: (optional) A list of ports on the inside of the docker container to be mapped to the outside.
- `netcat_services`: (optional) A list of ports on the inside of the docker container to be mapped to the outside.
- `build_script`: The command line command which will be used to build the challenge. If `changeable_flag` is true the flag to embed into the challenge will be piped into stdin. If `uses_docker` is set the challenge should define a docker container inside the `container` folder. If the challenge requires the solver to download files these files should be copied into the `downloads` folder. You do not have to create these folders, they will be created automatically. Exit with exit code 0 if the build succeeded, 1 otherwise.
- `solve_script`: The command line command which solves the challenge to verify it is solvable. It should exit with the exit code 0 if the challenge was solved successfully and the flag was verified or 1 otherwise. the correct flag will be piped into the stdin on the first row. On following rows, URLs to services will be piped in in the same order they were defined, with `website_services` coming before `netcat_services`.
- `changeable_flag`: Highly recommended to be true. This specifies if the build script is able to embed an arbitrary flag into the problem.
- `unlocked_by`: (optional) The exact title of the challenge that unlocks this one, if this challenge is part of a series and not the first one in that series.

If your python scripts require some libraries to run, put them in the root requirements.txt. A enviroment variable named TEST with the value of `true` will exist in all called scripts and docker containers if the challenge is being tested either localy or by travis, but not under the ctf. Only use this when absolutely necessary. Remember that all scripts should still work correctly in both cases.
