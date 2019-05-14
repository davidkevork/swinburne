using System;

namespace SwinAdventure.src
{
    public class LookCommand : Command
    {
        public LookCommand() : base(new String [] { "look" }) { }

        public override string Execute (Player p, string [] text)
        {
            int textLength = text.Length;
            if (textLength != 3 && textLength != 5)
            {
                return "I don't know how to look like that";
            }
            if (text[0] != "look")
            {
                return "Error in look input";
            }
            if (text[1] != "at")
            {
                return "What do you want to look at?";
            }
            if (textLength == 5 && text[3] != "in")
            {
                return "What do you want to look in?";
            }
            if (textLength == 3)
            {
                return LookAtIn(p, text[2], "inventory");
            }
            return LookAtIn(p, text[2], text[4]);
        }

        private IHaveInventory FetchContainer (Player p, string containerId)
        {
            return p.Locate(containerId) as IHaveInventory;
        }

        private string LookAtIn (Player p, string thingId, string containerId)
        {
            IHaveInventory container = FetchContainer(p, containerId);
            if (container == null)
            {
                return "I cannot find the "+ containerId;
            }
            GameObject containerThing = container.Locate(thingId);
            if (containerThing == null)
            {
                return "I cannot find the " + thingId + (containerId == "inventory" ? "" : " in the " + containerId);
            }
            return containerThing.FullDescription;
        }

        public string Description()
        {
            string data = "[look]  Usage: look at/in inventory\n";
            data += "\t\t\t\tlook at/in <item> in <container>\n";
            return data;
        }
    }
}
