import discord
import asyncio
import re
import json
import traceback
import time

time.sleep(5)  # give axela time to start

flag = input()

client = discord.Client()
messages = []


@client.event
async def on_ready():
    global axela
    print("starting")
    try:
        axela = client.get_guild(603684713361571879).get_member(601775203894427658)
        channel = client.get_channel(607937861156864040)

        assert axela.status != discord.Status.offline
        print("Axela online")

        await channel.send("Axela get users @me guilds")
        print("pm sent")
        await asyncio.sleep(3)
        response = json.loads(re.search(r"```(.*)```", messages[-1].content).group(1))
        guild_id = [
            int(i["id"]) for i in response if i["name"] == "Super Secret Server"
        ][0]
        print(f"guild_id:{guild_id}")
        await channel.send(f"Axela get guilds {guild_id} invites")
        print("pm sent")
        await asyncio.sleep(3)
        assert (
            json.loads(re.search(r"```(.*)```", messages[-1].content).group(1))[0][
                "code"
            ]
            == "GkadtPv"
        )
        print("code verified")
        recieved_flag = (
            await client.get_channel(601776233411510304).fetch_message(
                606576752927440896
            )
        ).content
        if flag != recieved_flag:
            print(f"flag missmatch {flag} {recieved_flag}")
            raise Exception
        print("flag verified")
    except Exception as e:
        print("something went wrong.")
        print(e)
        traceback.print_exc()
        exit(1)

    exit(0)


@client.event
async def on_message(message):
    global messages
    if message.author == axela:
        messages.append(message)


client.run(
    "redacted"
)

