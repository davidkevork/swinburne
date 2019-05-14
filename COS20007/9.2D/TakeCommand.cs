using System;
namespace SwinAdventure.src
{
    public class TakeCommand : Command
    {
        public TakeCommand() : base(new String[] { "pickup", "take" }) { }

        public override string Execute(Player p, string[] text)
        {
            int textLength = text.Length;
            if (textLength != 2 && textLength != 4)
            {
                return "I don't know what to take or pickup";
            }
            if (text[0] != "take" || text[0] != "pickup")
            {
                return "Error in take command";
            }
            string containerId = null;
            if (text.Length == 4)
            {
                containerId = text[3];
            }
            return TakeItem(p, text[1], containerId);
        }

        private IHaveInventory FetchContainer(Player p, string containerId)
        {
            return containerId == null ? p.Location : p.Locate(containerId) as IHaveInventory;
        }

        private string TakeItem(Player p, string thingId, string containerId)
        {
            IHaveInventory container = FetchContainer(p, containerId);
            if (container == null)
            {
                return "I cannot find the " + containerId;
            }
            GameObject containerThing = container.Locate(thingId);
            if (containerThing == null)
            {
                return "I cannot find the " + thingId + (containerId == null ? "" : " in the " + containerId);
            }
            bool dropped = container.Drop(thingId);
            return containerThing.FullDescription;
        }

        public string Description()
        {
            string data = "[take] Usage: take <item>\n";
            data += "\t\t\t\ttake <item> from <container>\n";
            return data;
        }
    }
}
