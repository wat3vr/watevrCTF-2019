import discord
import aiohttp
import json
import os

testing = os.environ.get("TEST") == "true"
print("testing?", testing)

client = discord.Client()
token = (
    "redacted"
)


@client.event
async def on_message(message):
    if message.author == client.user:
        return
    if not (
        (isinstance(message.channel, discord.DMChannel) and not testing)
        or message.channel.id == 607937861156864040
    ):
        return
    if message.content == "Axela help":
        await message.channel.send(
            """All commands:

Axela ping - ping
Axela say <phrase> - repeats the phrase
Axela get guilds <guild_id> - gets info about a specific guild
Axela get channels <channel_id> - gets info about a specific channel
Axela get users <user_id> gets info about a specific user
"""
        )
    elif message.content == "Axela ping":
        await message.channel.send("pong!")
    elif message.content.startswith("Axela say "):
        await message.channel.send(" ".join(message.content.split()[2:]))
    elif message.content.startswith("Axela get "):

        if "/" in message.content:
            await message.channel.send(
                "I dont like that character. Please don't use that."
            )
            return

        async with http.get(
            f'https://discordapp.com/api/{"/".join(message.content.split()[2:])}',
            headers={"Authorization": f"Bot {token}"},
        ) as r:
            raw_json = await r.text()
            response_json = json.loads(raw_json)
            print(f'https://discordapp.com/api/{"/".join(message.content.split()[2:])}')

            if "message" in response_json:  # error
                await message.channel.send(response_json["message"])
            elif "region" in response_json:  # guild
                embed = discord.Embed(
                    title=response_json["name"], description=response_json["region"]
                )
                embed.set_thumbnail(
                    url=f'https://cdn.discordapp.com/icons/{response_json["id"]}/{response_json["icon"]}.png'
                )
                embed.set_footer(text=f'owned by {response_json["owner_id"]}')
                await message.channel.send(embed=embed)

            elif "type" in response_json:  # channel
                embed = discord.Embed(title=response_json["name"])
                embed.set_footer(text=response_json["id"])
                await message.channel.send(embed=embed)

            elif "username" in response_json:  # user
                embed = discord.Embed(
                    title=f'{response_json["username"]}#{response_json["discriminator"]}'
                )
                embed.set_thumbnail(
                    url=f'https://cdn.discordapp.com/avatars/{response_json["id"]}/{response_json["avatar"]}.png'
                )
                embed.set_footer(text=response_json["id"])
                await message.channel.send(embed=embed)

            else:
                await message.channel.send(
                    f"Unrecognized response format```{raw_json}```"
                )
    else:
        await message.channel.send(
            "Unrecognized command. say `Axela help` to get a list of commands."
        )


@client.event
async def on_ready():
    global http
    http = aiohttp.ClientSession()
    print("ready")

    await client.get_channel(607937861156864040).send(f"Testing: {testing}")


client.run(token)
